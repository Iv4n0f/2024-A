<?php
session_start(); // Iniciar la sesión

// Verificar si el usuario no ha iniciado sesión
if(!isset($_SESSION['username'])) {
    header("Location: login.php"); // Redirigir si no está conectado
    exit;
}

$username = $_SESSION['username']; // Obtener el nombre de usuario de la sesión
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bienvenida</title>
</head>
<body>
    <h1>Bienvenido, <?php echo htmlspecialchars($username); ?>!</h1>
    <p>Esta es la página de bienvenida.</p>
    <a href="logout.php">Cerrar Sesión</a>
</body>
</html>

