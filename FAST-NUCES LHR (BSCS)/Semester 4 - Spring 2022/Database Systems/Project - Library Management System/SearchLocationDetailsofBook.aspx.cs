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
    public partial class SearchLocationDetailsofBook : System.Web.UI.Page
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

            found = objMyDal.SearchLocationDetailsofBook(Name, ref DT);

            if (found > 0)
            {
                LocationGrid.DataSource = DT;
                LocationGrid.DataBind();
                message.InnerHtml = Convert.ToString("Book is Available on Following Locations");
            }
            else
            {
                message.InnerHtml = Convert.ToString("Book is Currently Out Of Stock");
                LocationGrid.DataSource = null;
                LocationGrid.DataBind();
            }

        }
    }
}