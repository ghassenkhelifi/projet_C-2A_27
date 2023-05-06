<?php
include '../controller/EvenementC.php';
$evenementC = new evenementC();
$evenementC->deleteevenement($_GET["idevenement"]);
header('Location:ListEvenement.php');
