<?php
// Establecer una cookie con nombre "usuario" y valor "Juan"
setcookie("usuario", "Ivan Lopez", time() + 3600, "/");

// Verificar si la cookie está configurada
if(isset($_COOKIE['usuario'])) {
    echo "Hola " . $_COOKIE['usuario'];
} else {
    echo "No se encontró la cookie 'usuario'";
}

// Eliminar la cookie (configurándola con un tiempo en el pasado)
//setcookie("usuario", "", time() - 3600, "/");
?>

