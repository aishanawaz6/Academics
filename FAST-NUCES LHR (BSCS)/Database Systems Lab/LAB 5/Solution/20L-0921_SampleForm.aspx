<%@ Page Language="vb" AutoEventWireup="false" CodeBehind="WebForm1.aspx.vb" Inherits="WebApplication3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Label ID="Label1" runat="server" Text="Name:"></asp:Label>&nbsp
    <asp:TextBox ID="txtTextValue" Text=""
runat="server"></asp:TextBox>
        <br />
        <br />
        <asp:Label ID="Label2" runat="server" Text="Password:"></asp:Label>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <br />
        <br />
        <asp:Label ID="Label3" runat="server" Text="Text:"></asp:Label>
        <asp:TextBox ID="TextBox2" Text="Hello World!"
runat="server"></asp:TextBox>
        <br />
        <br />
         <br />
        <asp:Label ID="Label4" runat="server" Text="Comment:"></asp:Label>
        <asp:TextBox ID="txtComment" TextMode="multiline"
runat="server"></asp:TextBox>
        <br />
         <br />
        <asp:Label ID="Label5" runat="server" Text="Is Student:"></asp:Label>
        <asp:CheckBox ID="chkIsStudent" runat="server" />
        <br />
        <br />
        <asp:Label ID="Label6" runat="server" Text="Gender:"></asp:Label>&nbsp&nbsp
        <asp:Label ID="Label7" runat="server" Text="Male:"></asp:Label>&nbsp
         <asp:RadioButton ID="RadioButton1" runat="server" />&nbsp
          <asp:Label ID="Label8" runat="server" Text="Female:"></asp:Label>&nbsp
        <asp:RadioButton ID="RadioButton2" runat="server" />
        <br />
        <br />
        <asp:Label ID="Label9" runat="server" Text="Department:"></asp:Label>
        <asp:DropDownList ID="ddlDepartment" runat="server">
         <asp:ListItem Text="Select" Value="0"></asp:ListItem>
         <asp:ListItem Text="Computer Science"
   Value="CS"></asp:ListItem>
<asp:ListItem Text="Electrical Engineering"
Value="EE"></asp:ListItem>
<asp:ListItem Text="Business Administrator"
Value="BBA"></asp:ListItem>
<asp:ListItem Text="Civil Engineering"
Value="CV"></asp:ListItem>
</asp:DropDownList>
        <br />
        <br />
        <asp:Button ID="btnSave" Text="Save Form" runat="server" />

    </div>
    </form>
</body>
</html>
