const isEmpty = (str) => str.trim() === '';

function validar(){
  let dni = document.getElementById('dni');
  let nombres = document.getElementById('nombres');
  let apellidos = document.getElementById('apellidos');

  let dniVal = dni.value;
  let nombresVal = nombres.value;
  let apellidosVal = apellidos.value;

  tablaUsuarios = document.getElementById('tablaUsuarios');

  if( isEmpty(dniVal) || isEmpty(nombresVal)||isEmpty(apellidosVal)){
    alert('Todos los campos son obligatorios');
    return false;
  }
  return true;
};
