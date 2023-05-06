<?php

include '../controller/EvenementC.php';

$error = "";

// create evenement
$evenement = null;

// create an instance of the controller
$evenementC = new evenementC();
if (
    isset($_POST["idevenement"]) &&
    isset($_POST["titre"]) &&
    isset($_POST["description"]) &&
    isset($_POST["prix"]) &&
    isset($_POST["image"])  
   
) {
    if (
        !empty($_POST["idevenement"]) &&
        !empty($_POST['titre']) &&
        !empty($_POST["description"]) &&
        !empty($_POST["prix"]) &&
        !empty($_POST["image"]) 
         
    ) {
        $evenement = new evenement(
            $_POST['idevenement'],
            $_POST['titre'],
            $_POST['description'],
            $_POST['prix'],
            $_POST['image']
            

        );
        $evenementC->updateevenement($evenement, $_POST["idevenement"]);
        header('Location:ListEvenement.php');
    } else
        $error = "Missing information";
}
?>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Display</title>
</head>


<style>
       



       html,
body {
	height: 100%;
}

body {
	margin: 0;
	background: linear-gradient(45deg, #49a09d, #5f2c82);
	font-family: sans-serif;
	font-weight: 100;
}

.container {
	position: absolute;
	top: 50%;
	left: 50%;
	transform: translate(-50%, -50%);
}

table {
	width: 800px;
	border-collapse: collapse;
	overflow: hidden;
	box-shadow: 0 0 20px rgba(0,0,0,0.1);
}

th,
td {
	padding: 15px;
	background-color: rgba(255,255,255,0.2);
	color: #fff;
}

th {
	text-align: left;
}

thead {
	th {
		background-color: #55608f;
	}
}

tbody {
	tr {
		&:hover {
			background-color: rgba(255,255,255,0.3);
		}
	}
	td {
		position: relative;
		&:hover {
			&:before {
				content: "";
				position: absolute;
				left: 0;
				right: 0;
				top: -9999px;
				bottom: -9999px;
				background-color: rgba(255,255,255,0.2);
				z-index: -1;
			}
		}
	}
}








      </style>

<style>
        body {
          background-image: url("images/cinek.jpg");
          background-position: center;
          background-size: cover;
        }
      </style>

<body>
    <button><a href="ListEvenement.php">Back to list</a></button>
    <hr>

    <div id="error">
        <?php echo $error; ?>
    </div>

    <?php
    if (isset($_POST['idevenement'])) {
        $evenement = $evenementC->showevenement($_POST['idevenement']);

    ?>

        <form action="" method="POST">
            <table border="1" align="center">
                <tr>
                    <td>
                        <label for="idevenement">Id evenement:
                        </label>
                    </td>
                    <td><input type="text" name="idevenement" id="idevenement" value="<?php echo $evenement['idevenement']; ?>"></td>
                </tr>
                <tr>
                    <td>
                        <label for="titre">titre:
                        </label>
                    </td>
                    <td><input type="text" name="titre" id="titre" value="<?php echo $evenement['titre']; ?>"></td>
                </tr>
                <tr>
                    <td>
                        <label for="description">description:
                        </label>
                    </td>
                    <td><input type="text" name="description" id="description" value="<?php echo $evenement['description']; ?>"></td>
                </tr>
                <tr>
                    <td>
                        <label for="prix">prix:
                        </label>
                    </td>
                    <td>
                        <input type="text" name="prix" value="<?php echo $evenement['prix']; ?>" id="prix">
                    </td>
                </tr>
                
              
                <tr>
                    <td>
                        <label for="image">image:
                        </label>
                    </td>
                    <td>
                        <input type="file" name="image" value="<?php echo $evenement['image']; ?>" id="image">
                    </td>
                </tr>
                
              
              
              
              
              
              
                <tr>
                    <td></td>
                    <td>
                        <input type="submit" value="Update">
                    </td>
                    <td>
                        <input type="reset" value="Reset">
                    </td>
                </tr>
            </table>
        </form>
    <?php
    }
    ?>
</body>

</html>