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
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Search_Button_Click(object sender, EventArgs e)
        {

            String Name = TextBox1.Text;
            String Pass = TextBox2.Text;
            DataTable DT = new DataTable();

            myDAL objMyDal = new myDAL();

            int found;

            found = objMyDal.Login(Name,Pass, ref DT);

            if (found > 0)
            {
                LoginGrid.DataSource = DT;
                LoginGrid.DataBind();
                message.InnerHtml = Convert.ToString("Result:");
            }
            else
            {
                message.InnerHtml = Convert.ToString("-");
               LoginGrid.DataSource = null;
                LoginGrid.DataBind();
            }

        }
    }
}