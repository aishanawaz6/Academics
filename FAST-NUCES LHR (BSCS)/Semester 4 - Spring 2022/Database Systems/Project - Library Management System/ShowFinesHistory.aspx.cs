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
    public partial class ShowFinesHistory : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Search_Button_Click(object sender, EventArgs e)
        {

            String Name = TextBox1.Text;
            DataTable DT = new DataTable();

            myDAL objMyDal = new myDAL();

            int found;

            found = objMyDal.ShowFinesHistory(Name, ref DT);

            if (found > 0)
            {
                FineHistoryGrid.DataSource = DT;
                FineHistoryGrid.DataBind();
                message.InnerHtml = Convert.ToString("Following Customer Has Fines");
            }
            else
            {
                message.InnerHtml = Convert.ToString("No Customer with Fines History");
                FineHistoryGrid.DataSource = null;
                FineHistoryGrid.DataBind();
            }

        }
    }
}