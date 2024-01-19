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
    public partial class searchByLocation : System.Web.UI.Page
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
            found = objMyDal.searchByLoaction(Name, ref DT);

            if (found > 0)
            {
                LocationGrid.DataSource = DT;
                LocationGrid.DataBind();
                message.InnerHtml = Convert.ToString("This Location Has Following Books ");
            }
            else
            {
                message.InnerHtml = Convert.ToString("There is no Book at this Location");
                LocationGrid.DataSource = null;
                LocationGrid.DataBind();
            }

        }
    }
}