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
    public partial class dis : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Search_Button_Click(object sender, EventArgs e)
        {

            String Name = TextBox1.Text;
            String ui = TextBox8.Text;
           
            DataTable DT = new DataTable();
            myDAL objMyDal = new myDAL();
            int found;
            found = objMyDal.dis(Name, ui, ref DT);

            if (found > 0)
            {
                DisGrid.DataSource = DT;
                DisGrid.DataBind();
                message.InnerHtml = Convert.ToString("Booked!");
            }
            else
            {
                message.InnerHtml = Convert.ToString("Not Available");
                DisGrid.DataSource = null;
                DisGrid.DataBind();
            }

        }
    }
}