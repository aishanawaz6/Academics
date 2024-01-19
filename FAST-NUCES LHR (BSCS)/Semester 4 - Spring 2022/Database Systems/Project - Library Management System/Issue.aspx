<%@ Page Title="" Language="C#" MasterPageFile="~/MyMasterPage.Master" AutoEventWireup="true" CodeBehind="Issue.aspx.cs" Inherits="Library.Issue" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <img src="Images/Modern%20Public%20Library%20Logo%20Template.png" />
        <br />
    Issue Your Book 
        <br />
        <asp:Label ID="Label1" CssClass="LabelCSS" runat="server" Text="BookID"></asp:Label> &nbsp<asp:TextBox ID="txtName"  runat="server"></asp:TextBox>
        <br />
        <asp:Label ID="Label2" CssClass="LabelCSS" runat="server" Text="UserID"></asp:Label> &nbsp<asp:TextBox ID="TextBox1"  runat="server"></asp:TextBox>
        <br />
    <br/>
    <br/>
     <asp:Button ID="Button1" runat="server" Text="Issue." Font-Size="24" Font-Bold="True" ForeColor="black"  OnClick="Search_Button_Click" Height="45px" Width="207px" />
        <br/>
    <div id="message" runat="server">
    </div>
    <br/>
    <asp:GridView ID="IssueGrid" runat="server" Height="187px" Width="1265px">
    </asp:GridView>

</asp:Content>
