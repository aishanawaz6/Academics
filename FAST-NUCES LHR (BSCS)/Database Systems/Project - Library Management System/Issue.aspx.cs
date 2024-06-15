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
    public partial class Issue : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Search_Button_Click(object sender, EventArgs e)
        {

            String Name = txtName.Text;
            String ui = TextBox1.Text;
            DateTime date = DateTime.Now;
            DataTable DT = new DataTable();
            myDAL objMyDal = new myDAL();
            int found;
            found = objMyDal.Issue(Name, ui,date, ref DT);

            if (found > 0)
            {
                IssueGrid.DataSource = DT;
                IssueGrid.DataBind();
                message.InnerHtml = Convert.ToString("Book Issued!");
            }
            else
            {
                message.InnerHtml = Convert.ToString("Book Not Available");
               IssueGrid.DataSource = null;
                IssueGrid.DataBind();
            }

        }
    }
}