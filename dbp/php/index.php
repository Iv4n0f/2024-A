<!DOCTYPE html>
<html lang="es">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Numeros</title>
  <style>
    table {
      border-collapse: collapse;
      width: 100%;
    }

    th {
      border: 1px solid black;
      padding: 8px;
      text-align: center;
    }

    .red {
      color: red;
    }

    h1,h2{
      text-align: center;
    }
  </style>
</head>
      
<body>
  <h1>Numeros Naturales</h1>
  <h2 class = "red">Numeros pares</h2>
  <table>
    <tr>
      <?php
      for ($i = 0; $i <= 9; $i++) {
        $class = ($i % 2 == 0) ? " class='red'" : "";
        echo "<th$class>$i</th>";
      }
      ?>
    </tr>
  </table>
</body>

</html>   