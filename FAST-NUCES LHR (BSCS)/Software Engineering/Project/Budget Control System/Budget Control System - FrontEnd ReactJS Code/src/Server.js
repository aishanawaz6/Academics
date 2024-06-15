const express = require("express");
const sql = require("mssql/msnodesqlv8");
const cors = require("cors");

const app = express();

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(cors());

var config = {
  server: "ADNANRAZAQ-PC\\SQLADNAN2014",
  database: "bcs",
  driver: "msnodesqlv8",
  user: "sa",
  password: "12345678",
  option: {
    trustedConnection: true,
  },
};

/*sql.connect(config, function (err) {
  if (err) console.log(err);
  var request = new sql.Request();
  request.query(
    "SELECT t.customer_username, SUM(p.product_price) as total_price FROM Transactions t JOIN Product p ON t.product_id = p.product_id WHERE t.customer_username = 'faryalmakhdoom' AND p.product_category='Clothes' GROUP BY t.customer_username;",
    function (err, records) {
      if (err) {
        console.log(err);
      } else {
        console.log(records.recordset);
      }
    }
  );
});*/
/*sql.connect(config, function (err) {
  if (err) console.log(err);

  const gethist = new sql.Request();
  gethist.input("username", sql.VarChar, global.username);
  gethist.query(
   "select t.transaction_date,t.product_id,p.product_name,p.product_price from Transactions t join Product p on t.product_id=p.product_id where cust_username='danali1'",
    function (err, records) {
      if (err) {
       console.log(err)
      }
      else {
        console.log(records.recordset)
      }
    }
  );
});*/
app.post("/Signup", function (req, res) {
  const firstname = req.body.firstname;
  const lastname = req.body.lastname;
  const contact = req.body.contact;
  const username = req.body.username;
  const email = req.body.email;
  const password = req.body.password;

  sql.connect(config, function (err) {
    if (err) console.log(err);

    // insert data into the Customer table
    const insertRequest = new sql.Request();
    insertRequest.input("fname", sql.VarChar, firstname);
    insertRequest.input("lname", sql.VarChar, lastname);
    insertRequest.input("contact_no", sql.VarChar, contact);
    insertRequest.input("cust_username", sql.VarChar, username);
    insertRequest.input("customer_email", sql.VarChar, email);
    insertRequest.input("customer_password", sql.VarChar, password);
    insertRequest.query(
      "INSERT INTO Customer (fname,lname,contact_no,cust_username,customer_email,customer_password) VALUES (@fname,@lname,@contact_no,@cust_username,@customer_email,@customer_password)",
      (err, result) => {
        if (err) console.log(err);
        else console.log(result);
      }
    );
  });
});

app.post("/Login", (req, res) => {
  global.username = req.body.username;
  global.password = req.body.password;

  sql.connect(config, function (err) {
    if (err) console.log(err);

    const retrieveRequest = new sql.Request();
    retrieveRequest.input("username", sql.VarChar, global.username);
    retrieveRequest.input("password", sql.VarChar, global.password);
    retrieveRequest.query(
      " SELECT * FROM Customer WHERE cust_username = @username AND customer_password = @password",
      (err, result) => {
        if (err) {
          res.send({ err: err });
        }
        if (result.recordset.length > 0) {
          res.send(result);
          console.log(result);
        } else {
          res.send({ message: "Wrong Username/Password Combination" });
          console.log({ message: "LOGIN FAILED" });
        }
      }
    );
  });
});
app.post("/catreport", (req, res) => {
  sql.connect(config, function (err) {
    if (err) console.log(err);

    const sendexp = new sql.Request();
    sendexp.query(
     "SELECT t.customer_username,p.product_category, SUM(p.product_price) as total_price FROM Transactions t JOIN Product p ON t.product_id = p.product_id WHERE t.customer_username = 'faryalmakhdoom' AND p.product_category='Clothes' GROUP BY t.customer_username,p.product_category",
      function (err, records) {
        if (err) {
          res.send({ err: err });
        }
        if (records.recordset.length > 0) {
          res.send(records);
        } else {
          res.send({
            message: "No Transactions have been made in this Category",
          });
          console.log({ message: "NO RECORDS" });
        }
      }
    );
  });
});
app.post("/history", (req, res) => {
  sql.connect(config, function (err) {
    if (err) console.log(err);

    const gethist = new sql.Request();
    retrieveRequest.input("username", sql.VarChar, global.username);
    gethist.query(
     "select t.transaction_date,t.product_id,p.product_name,p.product_price from Transactions t join Product p on t.product_id=p.product_id where cust_username='@username'",
      function (err, records) {
        if (err) {
          res.send({ err: err });
        }
        if (records.recordset.length > 0) {
          res.send(records);
          console.log(records.recordset)
        } else {
          res.send({
            message: "No History",});
          console.log({ message: "NO RECORDS" });
        }
      }
    );
  });
});


app.listen(5000, function () {
  console.log("Server is running on port 5000");
  global.username = "";
  global.passwowrd = "";
});
