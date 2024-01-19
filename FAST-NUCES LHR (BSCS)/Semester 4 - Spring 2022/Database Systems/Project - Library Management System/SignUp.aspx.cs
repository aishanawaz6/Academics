using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using Library.DAL;


namespace Library
{
    public partial class SignUp : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Search_Button_Click(object sender, EventArgs e)
        {

            String userId = TextBox1.Text;
            String Fn = TextBox2.Text;
            String ln = TextBox3.Text;
            String age = TextBox4.Text;
            String ph = TextBox5.Text; ;
            String em = TextBox6.Text ;
            String G = TextBox9.Text;
            String pass = TextBox10.Text;
            String CNIC = TextBox7.Text;

            DataTable DT = new DataTable();

            myDAL objMyDal = new myDAL();

            int found;

            found = objMyDal.SignUp(userId,Fn,ln,age,ph,em,G,pass,CNIC, ref DT);

            if (found > 0)
            {
                SignUpGrid.DataSource = DT;
                SignUpGrid.DataBind();
                message.InnerHtml = Convert.ToString("Result:");
            }
            else
            {
                message.InnerHtml = Convert.ToString("-");
                SignUpGrid.DataSource = null;
               SignUpGrid.DataBind();
            }

        }
    }
}