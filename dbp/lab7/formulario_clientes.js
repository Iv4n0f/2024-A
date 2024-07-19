const isEmpty = (str) => str.trim() === "";

function isNumeric(str) {
  return /^\d+$/.test(str);
}

function validar() {
  let dni = document.getElementById("dni");
  let nombres = document.getElementById("nombres");
  let apellidos = document.getElementById("apellidos");
  let correo = document.getElementById("correo");
  let numero = document.getElementById("numero");

  let dniVal = dni.value;
  let nombresVal = nombres.value;
  let apellidosVal = apellidos.value;
  let correoVal = correo.value;
  let numeroVal = numero.value;

  if (
    isEmpty(dniVal) ||
    isEmpty(nombresVal) ||
    isEmpty(apellidosVal) ||
    isEmpty(correoVal) ||
    isEmpty(numeroVal)
  ) {
    alert("Todos los campos son obligatorios");
    return false;
  }

  if (!isNumeric(dniVal) || dniVal.length !== 8) {
    alert("El DNI debe tener 8 dígitos numéricos");
    return false;
  }

  if (!isNumeric(numeroVal) || numeroVal.length !== 9) {
    alert("El número debe tener 9 dígitos numéricos");
    return false;
  }

  return true;
}
