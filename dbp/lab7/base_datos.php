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
      throw new Exception('Error de conexión: ' . mysqli_connect_error());
    }
  }

  public function getClientes()
  {
    $result = mysqli_query($this->conexion, 'SELECT * FROM clientes');
    if (!$result) {
      throw new Exception('Error al obtener clientes: ' . mysqli_error($this->conexion));
    }
    if (mysqli_num_rows($result) > 0) {
      return $result;
    } else {
      throw new Exception('No se encontraron clientes.');
    }
    return null;
  }

  public function insCliente($dni, $nombres, $apellidos, $correo, $numero)
  {
    $stmt = $this->conexion->prepare('INSERT INTO clientes (dni, nombres, apellidos, correo, numero) VALUES (?, ?, ?, ?, ?)');
    if (!$stmt) {
      throw new Exception('Error en la preparación de la consulta: ' . $this->conexion->error);
    }
    $stmt->bind_param('sssss', $dni, $nombres, $apellidos, $correo, $numero);
    if (!$stmt->execute()) {
      throw new Exception('Error al insertar cliente: ' . $stmt->error);
    }
  }

  public function cerrar()
  {
    mysqli_close($this->conexion);
  }
}
