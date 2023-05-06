<?php

include '../controller/EvenementC.php';

$error = "";

// create evenement
$evenement = null;

// create an instance of the controller
$evenementC = new evenementC();
if (
    isset($_POST["titre"]) &&
    isset($_POST["description"]) &&
    isset($_POST["prix"])&&
    isset($_POST["image"]) 
    
) {
    if (
        !empty($_POST['titre']) &&
        !empty($_POST["description"]) &&
        !empty($_POST["prix"])&&
        !empty($_POST["image"])  
       
    ) {
        $evenement = new evenement(
            null,
            $_POST['titre'],
            $_POST['description'],
            $_POST['prix'],
            $_POST['image']
           
        );
        $evenementC->addevenement($evenement);
        header('Location:Listevenement.php');
    } else
        $error = "Missing information";
}








?>

<style>



.input {
  border: none;
  outline: none;
  border-radius: 15px;
  padding: 1em;
  background-color: #ccc;
  box-shadow: inset 2px 5px 10px rgba(0,0,0,0.3);
  transition: 300ms ease-in-out;
}

.input:focus {
  background-color: white;
  transform: scale(1.05);
  box-shadow: 13px 13px 100px #969696,
             -13px -13px 100px #ffffff;
}



label {
color: #B4886B;
font-weight: bold;
display: block;
width: 150px;
float: left;
}






</style>




<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Display</title>



    <style>
        body {
          background-image: url("images/cinek.jpg");
          background-position: center;
          background-size: cover;
        }
      </style>




</head>

<body>
   
<script src="controle saisie.js"></script>

    <a href="ListEvenement.php">Back to list </a>
    <hr>

   



  <form action="" method="POST" >
    
   
        <table border="0" align="center">

           
    
    
             <tr>
                <td>
                    <label for="titre">titre:
                    </label>
                </td>
                <td><input class="input" type="text" name="titre" id="titre" placeholder="Your Name" onkeyup="saisie()">  <label id="error"></label> </td>
               
            
            
            </tr>

            <tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>

            
           
            <tr>
                <td>
                    <label for="description">description:
                    </label>
                </td>
                <td><input class="input" type="text" name="description" id="description" placeholder="Your Name"  onkeyup="saisie()">   <label id="error1"></label>                 </td>
               
            </tr>
           



            <tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>


            <tr>
                <td>
                    <label for="prix">prix:
                    </label>
                </td>
                <td>
                    <input class="input" type="text" name="prix" id="prix" placeholder="Your Name"  onkeyup="saisie()">          <label id="error2"></label>             </td>
                
            </tr>


            <tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>

            <tr>
                <td>
                    <label for="image">image:
                    </label>
                </td>
                <td>
                    <input  type="file" name="image" id="image">
                </td>
            </tr>

    
            <tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
<tr></tr>
            
            <tr align="center">
                <td>
                    <input class="input" type="submit" value="Save">
                </td>
                <td>
                    <input class="input" type="reset" value="Reset">
                </td>
            </tr>
        </table>
    </form>
</body>

</html>