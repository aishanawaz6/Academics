<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="L00921_Lab10_Ex1.aspx.cs" Inherits="Lab09_DBS.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
   <script type="text/javascript">
        function convertFromRs(){
            var FirstNumber = document.getElementById('txtName').value;
            var selectedMedium = document.getElementById('CurrencySelect').value;
            var out;
            if (selectedMedium == "Dollar")
            {
                out=parseFloat(FirstNumber) * 0.0052;
            }
            else
                if (selectedMedium == "Euro")
                {
                    out = parseFloat(FirstNumber) * 0.0050 ;
                }
            else
                if (selectedMedium == "Pound")
                    {
                    out = parseFloat(FirstNumber) * 0.0043;
                    }
            document.getElementById('TextBox1').value = out;

        
       }
       function convertToRs()
       {
           var FirstNumber = document.getElementById('TextBox2').value;
           var selectedMedium = document.getElementById('CurrencySelect').value;
           var out;
           if (selectedMedium == "Dollar") {
               out = parseFloat(FirstNumber) * 191.75;
           }
           else
               if (selectedMedium == "Euro") {
                   out = parseFloat(FirstNumber) * 199.63;
               }
               else
                   if (selectedMedium == "Pound") {
                       out = parseFloat(FirstNumber) * 234.67;
                   }
           document.getElementById('TextBox3').value = out;

       }
       function resetIt() {
           var selectedMedium = document.getElementById('CurrencySelect').value;

           document.getElementById('TextBox4').value = selectedMedium;
           document.getElementById('TextBox5').value = "Aisha 20L-0921";

           document.getElementById('TextBox3').value ="";
           document.getElementById('txtName').value = "";
           document.getElementById('CurrencySelect').value = "";;
           document.getElementById('TextBox1').value = "";
           document.getElementById('TextBox2').value = "";

       }
   </script>
    <style>

        body {
            font-family: @'Times New Roman'
            font-size: 4em;
            color:purple;
            background-color: lightgray
        }
         h1 {
        font-family: @'Microsoft JhengHei';
        color: Blue;
        }
         .buttonCSS{
             font-family='Times New Roman';
             font-size: large;
              background-color: lightgray
         
   height: 30px;
              width=400px;

        color: blue;
        border: 3px solid;
        border-color:blueviolet;
        box-shadow:0px 0px 5px 1px darkmagenta; border-radius: 25px;
            
        }
        .textbox {
  height: 20px;
        color: Black;
        border: 3px solid;
        border-color:blueviolet;
        box-shadow:0px 0px 5px 1px green; border-radius: 5px
        }
          #submit{
  position: absolute;
    top:50%;
    background-color:#0a0a23;
    color: #fff;
    border:none;
    border-radius:10px;
        }
        .css3 {
             font-family='Times New Roman';
             font-size: large;
             color :red;
              background-color: lightgray
   height: 30px;
             color:red;

       
        border: 3px solid;
        border-color:red;
        box-shadow:0px 0px 5px 1px red; border-radius: 25px;
            
        }
        .buttonCSS2 {
          height: 30px;
        color: Black;
        border: 3px solid;
        border-color:blueviolet;
        box-shadow:0px 0px 5px 1px blue; border-radius: 5px
        }
        </style>
<body>
    <form id="form1" runat="server">
    <div>
        <h1>Currency Converting Web Site</h1>
        <br />
        <br />
        Select Currency Medium: &nbsp &nbsp &nbsp

   <asp:DropDownList ID="CurrencySelect" CssClass="buttonCSS2" runat="server">
       <asp:ListItem Text="Select" Value="0"></asp:ListItem>
       <asp:ListItem Text="Dollar"
Value="Dollar"></asp:ListItem>
<asp:ListItem Text="Euro"
Value="Euro"></asp:ListItem>
<asp:ListItem Text="Pound"
Value="Pound"></asp:ListItem>
</asp:DropDownList>
        <br />
        <br />
        Please Enter amount in Rupees to Convert to your Selected Medium:  &nbsp &nbsp &nbsp 
     <asp:TextBox ID="txtName" CssClass="textbox" runat="server"></asp:TextBox>
 <br />
        <br />
        <asp:Button ID="Button1" CssClass="buttonCSS" runat="server" OnClientClick="javascript:convertFromRs();" Text="  Convert Rupees To Selected Medium  " />
        <br />
        <br />
        Amount from Rupees to your chosen medium:  &nbsp &nbsp &nbsp
        <asp:TextBox ID="TextBox1" CssClass="textbox" runat="server"></asp:TextBox>
           <br />
        <br />
        Please enter amount in  your chosen medium to convert to Rupees:  &nbsp &nbsp &nbsp
      <asp:TextBox ID="TextBox2" CssClass="textbox" runat="server"></asp:TextBox>
         <br />
        <br />
        <asp:Button ID="Button2" CssClass="buttonCSS" runat="server" OnClientClick="javascript:convertToRs();" Text="  Convert from Selected Medium to Rupees  " />
          <br />
        <br />
        Amount from your chosen medium to Rupees:  &nbsp &nbsp &nbsp
        <asp:TextBox ID="TextBox3" CssClass="textbox" runat="server"></asp:TextBox>
            <br />
        <br />
        Your Prevoious Chosen Medium was:  &nbsp &nbsp &nbsp
        <asp:TextBox ID="TextBox4" CssClass="textbox" runat="server"></asp:TextBox>
            <br />
        <br />
        Programmed by: 
         <asp:TextBox ID="TextBox5" CssClass="textbox" runat="server"></asp:TextBox>
         <br />
        <br />
        <asp:Button ID="Button3" CssClass="css3" runat="server" OnClientClick="javascriot:resetIt();" Text="Reset" />
       
       </div>  
    </form>
</body>
</html>
