<?php
session_start(); // Iniciar la sesión

// Verificar si el usuario ya inició sesión
if(isset($_SESSION['username'])) {
    header("Location: bienvenida.php"); // Redirigir si ya está conectado
    exit;//:v
}

// Verificar si se ha enviado el formulario
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Validar el nombre de usuario (ajajhsj)
    if ($_POST['username'] == "usuario") {
        $_SESSION['username'] = $_POST['username']; // Almacenar el nombre de usuario en la sesión
        header("Location: bienvenida.php"); // Redirigir a la página de bienvenida
        exit;
    } else {
        $error = "Nombre de usuario incorrecto";
    }
}
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Iniciar Sesión</title>
</head>
<body>
    <h1>Iniciar Sesión</h1>
    <?php if(isset($error)) { echo "<p>$error</p>"; } ?>
    <form action="" method="post">
        <label for="username">Nombre de Usuario:</label>
        <input type="text" id="username" name="username" required><br><br>
        <input type="submit" value="Iniciar Sesión">
    </form>
</body>
</html>
