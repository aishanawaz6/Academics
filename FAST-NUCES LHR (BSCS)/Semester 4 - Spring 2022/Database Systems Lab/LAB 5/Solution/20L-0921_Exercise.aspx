<%@ Page Language="vb" AutoEventWireup="false" CodeBehind="WebForm2.aspx.vb" Inherits="WebApplication3.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <img src="images/download.jpg" />
        <br />
        &nbsp
        &nbsp
        &nbsp
       <b> <asp:Label ID="Label1" runat="server" Text="Create an account"></asp:Label></b>
        <br />
        <br />
        <asp:Label ID="Label2" runat="server" Text="First Name:"></asp:Label>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:Label ID="Label3" runat="server" Text="Last Name:"></asp:Label>
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <br />
         <br />
        <asp:Label ID="Label11" runat="server" Text="User Name:"></asp:Label>
        <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
         <br />
         <br />
        <asp:Label ID="Label4" runat="server" Text="Password:"></asp:Label>
      <asp:TextBox ID="txtPassword" TextMode="password"
runat="server"></asp:TextBox>
        <br />
         <br />
        <asp:Label ID="Label5" runat="server" Text="Date of Birth:"></asp:Label>
        <br />
        <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
         <br />
         <br />
        <asp:Label ID="Label6" runat="server" Text="Country:"></asp:Label>
        <asp:DropDownList ID="ddlCountry" runat="server">
<asp:ListItem Text="Select" Value="0"></asp:ListItem>
<asp:ListItem Text="Pakistan"
Value="Pakistan"></asp:ListItem>
<asp:ListItem Text="Kuwait"
Value="Kuwait"></asp:ListItem>
<asp:ListItem Text="USA"
Value="USA"></asp:ListItem>
<asp:ListItem Text="UAE"
Value="UAE"></asp:ListItem>
</asp:DropDownList>
        <br />
        <br />
        <asp:Label ID="Label7" runat="server" Text="Gender:"></asp:Label>
        <asp:RadioButton ID="RadioButton1" runat="server" />
        <asp:Label ID="Label8" runat="server" Text="Male"></asp:Label>
        <asp:RadioButton ID="RadioButton2" runat="server" />
        <asp:Label ID="Label9" runat="server" Text="Female"></asp:Label>
        <br />
        <br />
        <asp:CheckBox ID="CheckBox1" runat="server" />&nbsp
        <asp:Label ID="Label10" runat="server" Text="Enable Privacy"></asp:Label>
        <br />
        <br />
        <asp:Button ID="btnSave" Text="Create Account" runat="server" />
    </div>
    </form>
</body>
</html>
