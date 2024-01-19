using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;


namespace Library.DAL
{
    public class myDAL
    {
        private static readonly string connString =
System.Configuration.ConfigurationManager.ConnectionStrings["SQLDbConnection"].ConnectionString;

        public DataSet SelectBooks() //to get the values of all the Books from table Books and return the Dataset
        {

            DataSet ds = new DataSet(); //declare and instantiate new dataset
            SqlConnection con = new SqlConnection(connString); //declare and instantiate new SQL connection
            con.Open(); // open sql Connection
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("Select * from Books", con);  //instantiate SQL command 
                cmd.CommandType = CommandType.Text; //set type of sqL Command
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                {
                    da.Fill(ds); //Add the result  set  returned from SQLCommand to ds
                }
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }

            return ds; //return the dataset
        }
        public int SearchItem(String Name, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("SearchABook ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@BookName", SqlDbType.VarChar, 200);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@BookName"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                /* Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {*/
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                //}


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int SearchByGenre(String Name, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("SearchByGenre ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@gen", SqlDbType.VarChar, 100);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@gen"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                /* Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {*/
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                //}


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int BSByAuthor(String Name, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("searchAuthorBestSelling ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@authorName", SqlDbType.VarChar, 200);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@authorName"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                /* Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {*/
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                //}


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int AuthorDetails(String Name, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("AllDetailsOfAuthor ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@AuthorName", SqlDbType.VarChar, 200);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@AuthorName"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                /* Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {*/
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                //}


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int Login(String Name, String Pass, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("getLoginDetails ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@Usern", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@passw", SqlDbType.VarChar, 50);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@Usern"].Value = Name;
                cmd.Parameters["@passw"].Value = Pass;


                cmd.ExecuteNonQuery();

                // read output value 
                /* Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {*/
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                //}


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int SignUp(String userId, String Fn, String ln, String age, String ph, String em, String G, String CNIC, String pass, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("signUp ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@UI", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@fn", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@ln", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@ag", SqlDbType.Int, 50);
                cmd.Parameters.Add("@ph", SqlDbType.VarChar, 20);
                cmd.Parameters.Add("@em", SqlDbType.VarChar, 50);
                cmd.Parameters.Add("@G", SqlDbType.VarChar, 10);
                cmd.Parameters.Add("@pass", SqlDbType.VarChar, 50);
                cmd.Parameters.Add("@cnic", SqlDbType.VarChar, 60);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@UI"].Value = userId;
                cmd.Parameters["@fn"].Value = Fn;
                cmd.Parameters["@ln"].Value = ln;
                cmd.Parameters["@ag"].Value = age;
                cmd.Parameters["@ph"].Value = ph;
                cmd.Parameters["@em"].Value = em;
                cmd.Parameters["@G"].Value = G;
                cmd.Parameters["@pass"].Value = pass;
                cmd.Parameters["@cnic"].Value = CNIC;


                cmd.ExecuteNonQuery();

                // read output value 
                /* Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {*/
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                //}


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int showRecommendations(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("showRecommendations", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@uID", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@uID"].Value = Name;
                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                    {
                        da.Fill(ds);
                    }
                    DT = ds.Tables[0];
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int ShowFinesHistory(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("ShowFinesHistory ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@uID", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@uID"].Value = Name;
                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                    {
                        da.Fill(ds);
                    }
                    DT = ds.Tables[0];
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }
            return Found;
        }
        public int SearchLocationDetailsofBook(String Name, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("SearchLocationDetailsofBook ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@BookN", SqlDbType.VarChar, 200);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@BookN"].Value = Name;
                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                    {
                        da.Fill(ds);
                    }
                    DT = ds.Tables[0];
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int SearchBooksByType(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("SearchBooksByType", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@bt", SqlDbType.VarChar, 200);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@bt"].Value = Name;
                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                    {
                        da.Fill(ds);
                    }
                    DT = ds.Tables[0];
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int SearchMembershipDetails(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("SearchMembershipDetails", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@uID", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@uID"].Value = Name;
                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                    {
                        da.Fill(ds);
                    }
                    DT = ds.Tables[0];
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int showMyDetails(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("showMyDetails", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@uID", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@uID"].Value = Name;
                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))
                    {
                        da.Fill(ds);
                    }
                    DT = ds.Tables[0];
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int searchByLoaction(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("searchByLoaction ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;
                //@ln nvarchar(200)
                cmd.Parameters.Add("@ln", SqlDbType.NVarChar, 200);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@ln"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                    {
                        da.Fill(ds);

                    }

                    DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int FindIssuedTo(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("FindIssuedTo ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;
                //@ln nvarchar(200)
                cmd.Parameters.Add("@BI", SqlDbType.NVarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@BI"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                    {
                        da.Fill(ds);

                    }

                    DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int searchBookByRatings(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("searchBookByRatings ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;
                //@ln nvarchar(200)
                cmd.Parameters.Add("@rat", SqlDbType.NVarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@rat"].Value = Name;


                cmd.ExecuteNonQuery();

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                    {
                        da.Fill(ds);

                    }

                    DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int searchSuggestionofBook(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("searchSuggestionofBook ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;
                //@ln nvarchar(200)
                cmd.Parameters.Add("@bn", SqlDbType.NVarChar, 200);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;
                // set parameter values
                cmd.Parameters["@bn"].Value = Name;
                cmd.ExecuteNonQuery();
                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                    {
                        da.Fill(ds);

                    }

                    DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int searchDiscussionRoom(String Name, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("searchDiscussionRoom ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@ri", SqlDbType.NVarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;
                // set parameter values
                cmd.Parameters["@ri"].Value = Name;
                cmd.ExecuteNonQuery();
                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                    {
                        da.Fill(ds);

                    }

                    DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int Issue(String Name,String ui,DateTime date, ref DataTable DT)
        {

            int Found = 1;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("IssueABook ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@BookId", SqlDbType.VarChar, 200);
                cmd.Parameters.Add("@uID", SqlDbType.VarChar, 100);
                cmd.Parameters.Add("@issue_date", SqlDbType.DateTime, 100);
                // cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@BookId"].Value = Name;
                cmd.Parameters["@uID"].Value = ui;
                cmd.Parameters["@issue_date"].Value = date;


                cmd.ExecuteNonQuery();

                // read output value 
                 Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                 if (Found == 1)
                 {
                using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                {
                    da.Fill(ds);

                }

                DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
        public int dis(String Name,String ui, ref DataTable DT)
        {

            int Found = 0;
            DataSet ds = new DataSet();
            SqlConnection con = new SqlConnection(connString);
            con.Open();
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("DiscussionRoom_Booking ", con); //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@ui", SqlDbType.NVarChar, 100);
                cmd.Parameters.Add("@ri", SqlDbType.NVarChar, 100);
                cmd.Parameters.Add("@Found", SqlDbType.Int).Direction = ParameterDirection.Output;
                // set parameter values
                cmd.Parameters["@ui"].Value = Name;
                cmd.Parameters["@ri"].Value = ui;
                cmd.ExecuteNonQuery();
                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Found"].Value); //convert to output parameter to interger format

                if (Found == 1)
                {
                    using (SqlDataAdapter da = new SqlDataAdapter(cmd))

                    {
                        da.Fill(ds);

                    }

                    DT = ds.Tables[0];

                }


                con.Close();


            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());

            }
            finally
            {
                con.Close();
            }

            return Found;

        }
    }
}
