using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Library.DAL;

namespace Library
{
    public partial class Books : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            LoadGrid();
        }
        public void LoadGrid()
        {
            myDAL objMyDAL = new myDAL();
            BookGrid.DataSource = objMyDAL.SelectBooks();
            BookGrid.DataBind();
        }
    }
}