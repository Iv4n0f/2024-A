<?php include 'base_datos.php'; ?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Formulario Registro Clientes</title>
  <link rel="stylesheet" href="formulario_clientes.css">
  <script type="text/javascript" src="formulario_clientes.js"></script>
</head>

<body>

  <div class="contenedor">
    <h2>Formulario de registro</h2>
    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>" onsubmit="return validar();">
      <div class="relleno">
        <div class="col_50">
          <input class="campos" id="dni" name="dni" type="number" placeholder="DNI...">
        </div>
        <div class="col_50">
          <input class="campos" id="nombres" name="nombres" type="text" placeholder="Nombres...">
        </div>
        <div class="col_100">
          <input class="campos" id="apellidos" name="apellidos" type="text" placeholder="Apellidos...">
        </div>
        <div class="col_50">
          <input class="campos" id="correo" name="correo" type="email" placeholder="Correo...">
        </div>
        <div class="col_50">
          <input class="campos" id="numero" name="numero" type="number" placeholder="Numero...">
        </div>
        <button id="btnAgregar" class="btn" type="submit">Agregar</button>
      </div>
    </form>
  </div>

  <h2 style="text-align: center;">Clientes registrados</h2>
  <table id="tablaUsuarios" class="tabla">
    <thead>
      <tr>
        <th>DNI</th>
        <th>Nombres</th>
        <th>Apellidos</th>
        <th>Correo</th>
        <th>Número</th>
      </tr>
    </thead>
    <tbody>
      <?php
      $bd = new BaseDatos('localhost', 'user', 'password', 'dbp');
      $bd->conectar();

      if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $dni = $_POST['dni'];
        $nom = $_POST['nombres'];
        $apel = $_POST['apellidos'];
        $email = $_POST['correo'];
        $num = $_POST['numero'];

        $bd->insCliente($dni, $nom, $apel, $email, $num);
      }

      $clientes = $bd->getClientes();
      if (!is_null($clientes)) {
        while ($row = mysqli_fetch_assoc($clientes)) {
          echo '<tr>';
          echo '<td>' . $row['dni'] . '</td>';
          echo '<td>' . $row['nombres'] . '</td>';
          echo '<td>' . $row['apellidos'] . '</td>';
          echo '<td>' . $row['correo'] . '</td>';
          echo '<td>' . $row['numero'] . '</td>';
          echo '</tr>';
        }
      }
      $bd->cerrar();
      ?>
    </tbody>
  </table>

</body>

<html>
