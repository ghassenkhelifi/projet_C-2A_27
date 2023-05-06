<?php
require('E:/php/htdocs/fpdf/fpdfassistant.php');

// Connexion à la base de données avec PDO
$dsn = "mysql:host=localhost;dbname=atelierphp";
$user = "root";
$password = "";
$options = array(
    PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
);

try {
    $conn = new PDO($dsn, $user, $password, $options);
} catch (PDOException $e) {
    echo "Erreur de connexion : " . $e->getMessage();
}

// Requête SQL pour récupérer les données
$sql = "SELECT * FROM evenement";
$result = $conn->query($sql);

// Création du PDF
$pdf = new FPDF();
$pdf->AddPage();
$pdf->SetFont('Arial','B',10);

while ($row = $result->fetch(PDO::FETCH_ASSOC)) {
    $pdf->Cell(40,10,$row['idevenement'],1);
    $pdf->Cell(40,10,$row['titre'],1);
    $pdf->Cell(80,10,$row['prix'],1);
    $pdf->Cell(30,10,$row['image'],1);
    $pdf->Ln();
}

// Envoi du PDF au navigateur
$pdf->Output('F', 'E:/php/htdocs/ghassen.pdf');
?>
