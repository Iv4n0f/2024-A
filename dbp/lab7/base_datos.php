<?php

class BaseDatos
{
  private $host;

  private $usua;

  private $pass;

  private $bd;

  private $conexion;

  public function __construct($host, $usua, $pass, $bd)
  {
    $this->host = $host;
    $this->usua = $usua;
    $this->pass = $pass;
    $this->bd = $bd;
  }

  public function conectar()
  {
    $this->conexion = mysqli_connect($this->host, $this->usua, $this->pass, $this->bd);
    $this->conexion->set_charset('utf8');
    if (mysqli_connect_errno()) {
      echo 'error de conexion';
    }
  }

  public function getClientes()
  {
    $result = mysqli_query($this->conexion, 'SELECT * FROM clientes');
    $error = mysqli_error($this->conexion);
    if (empty($error)) {
      if (mysqli_num_rows($result) > 0) {
        return $result;
      }
    } else {
      echo 'error al obtener clientes';
    }

    return null;
  }

  public function insCliente($dni, $nomb, $apel)
  {
    mysqli_query($this->conexion, 'INSERT INTO clientes VALUES (' . $dni . ", '" . $nomb . "','" . $apel . "')");
    $error = mysqli_error($this->conexion);
    if (empty($error)) {
      return true;
    }
    echo 'error al insertar cliente';
  }

  public function cerrar()
  {
    mysqli_close($this->conexion);
  }
}
?>
