<!DOCTYPE html>
<html lang="es">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Calcular IMC</title>
</head>

<body>
  <?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $nombre = $_POST['nombre'];
    $email = $_POST['email'];
    $edad = $_POST['edad'];
    $genero = $_POST['genero'];
    $peso = $_POST['peso'];
    $estatura = $_POST['estatura'];
    $p_abdominal = $_POST['p_abdominal'];

    echo 'Nombre: ' . htmlspecialchars($nombre) . '<br>';
    echo 'Email: ' . htmlspecialchars($email) . '<br>';
    echo 'Edad: ' . htmlspecialchars($edad) . '<br>';
    echo 'Género: ' . htmlspecialchars($genero) . '<br>';
    echo 'Peso: ' . htmlspecialchars($peso) . ' kg<br>';
    echo 'Estatura: ' . htmlspecialchars($estatura) . ' m<br>';
    echo 'Perímetro Abdominal: ' . htmlspecialchars($p_abdominal) . ' cm<br>';

    // Calcular el IMC
    $estatura_cm = $estatura / 100;
    $imc = $peso / ($estatura_cm * $estatura_cm);
    echo 'IMC: ' . number_format($imc, 2) . '<br>';

    echo 'Interpretacion perimetro abdominal: ';
    // Perimetro abdominal segun genero
    if ($genero == 'masculino') {
        if ($p_abdominal < 94) {
            echo 'Normal<br>';
        } else if ($p_abdominal <= 102) {
            echo 'Aumento de riesgo de problemas metabolicos y cardiovasculares <br>';
        } else if ($p_abdominal > 102) {
            echo 'Riesgo significativamnete elevado <br>';
        }
    }

    if ($genero == 'femenino') {
        if ($p_abdominal < 80) {
            echo 'Normal<br>';
        } else if ($p_abdominal <= 88) {
            echo 'Aumento de riesgo de problemas metabolicos y cardiovasculares <br>';
        } else if ($p_abdominal > 88) {
            echo 'Riesgo significativamnete elevado <br>';
        }
    }
} else {
    ?>
    <form action="" method="post">
      <label for="nombre">Nombre:</label>
      <input type="text" id="nombre" name="nombre" required><br><br>
      <label for="email">Email:</label>
      <input type="email" id="email" name="email" required><br><br>
      <label for="edad">Edad:</label>
      <input type="number" id="edad" name="edad" required><br><br>
      <label for="genero">Género:</label>
      <select id="genero" name="genero" required>
        <option value="masculino">Masculino</option>
        <option value="femenino">Femenino</option>
      </select><br><br>
      <label for="peso">Peso (kg):</label>
      <input type="number" id="peso" name="peso" required><br><br>
      <label for="estatura">Estatura (cm):</label>
      <input type="number" id="estatura" name="estatura" required><br><br>
      <label for="p_abdominal">Perímetro Abdominal (cm):</label>
      <input type="number" id="p_abdominal" name="p_abdominal" required><br><br>
      <input type="submit" value="Enviar">
    </form>
  <?php
}
?>
</body>

</html>
