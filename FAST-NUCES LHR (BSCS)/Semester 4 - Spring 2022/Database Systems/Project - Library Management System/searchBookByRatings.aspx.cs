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
    public partial class searchBookByRatings : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Search_Button_Click(object sender, EventArgs e)
        {

            String Name = TextBox1.Text;
            DataTable DT = new DataTable();
            myDAL objMyDal = new myDAL();
            int found = 0;
            found = objMyDal.searchBookByRatings(Name, ref DT);

            if (found > 0)
            {
                RatingsGrid.DataSource = DT;
                RatingsGrid.DataBind();
                message.InnerHtml = Convert.ToString("Following Required Rated Books Found");
            }
            else
            {
                message.InnerHtml = Convert.ToString("Required Rated Book Not Found");
                RatingsGrid.DataSource = null;
                RatingsGrid.DataBind();
            }

        }



    }
}