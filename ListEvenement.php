<?php
include '../controller/EvenementC.php';
$evenementC = new evenementC();
$list = $evenementC->listevenement();
?>
<html>






  
   
    
   





<head>

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

    
</style>

<style>
        body {
          background-image: url("images/cinek.jpg");
          background-position: center;
          background-size: cover;
        }
      </style>
 






<body>
<a href="http://localhost/workshop5/view/evenemnt.php">Back ADMIN </a>
    <center>
        <h1>List of evenements</h1>
        <h2>
            <a href="addEvenement.php">Add evenement</a>
        </h2>
    </center>
    <table border="1" align="center" width="70%">
        <tr>
            <th>Id evenement</th>
            <th>titre</th>
            <th>description</th>
            <th>prix</th>
            <th>image</th>
           
            <th>Update</th>
            <th>Delete</th>
        </tr>
        <?php
        foreach ($list as $evenement) {
        ?>
            <tr>
                <td><?= $evenement['idevenement']; ?></td>
                <td><?= $evenement['titre']; ?></td>
                <td><?= $evenement['description']; ?></td>
                <td><?= $evenement['prix']; ?></td>
                <td><?= $evenement['image']; ?></td>
                

                
                
                <td align="center">
                    <form method="POST" action="updateEvenement.php">
                        <input type="submit" name="update" value="Update">
                        <input type="hidden" value=<?PHP echo $evenement['idevenement']; ?> name="idevenement">
                    </form>
                </td>
                <td>
                    <a href="deleteEvenement.php?idevenement=<?php echo $evenement['idevenement']; ?>">Delete</a>
                </td>
            </tr>
       
      
       
       
       <?php
        }
        ?>
    </table>


    <div style="text-align: center;">
    <button onclick="window.open('generer_pdf.php')" class="pdf-button">Générer PDF</button>
    </div>
     
    
    <form method="post" action="stat.php" align="center">
          <input class="btn btn-sm btn-primary" type="submit" name="stat" value="Statistique">
        </form>






    </body>




</html>