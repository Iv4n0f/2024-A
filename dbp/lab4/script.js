function unirNombres() {
  let primer_nombre = document.getElementById("primer_nombre").value;
  let segundo_nombre = document.getElementById("segundo_nombre").value;
  let primer_apellido = document.getElementById("primer_apellido").value;
  let segundo_apellido = document.getElementById("segundo_apellido").value;

  const nombre_completo = `${primer_nombre} ${segundo_nombre} ${primer_apellido} ${segundo_apellido}`;
  document.getElementById("nombre_completo").value = nombre_completo;
  return false;
}

function ultimoDigito() {
  let dni = document.getElementById("dni").value;
  if (dni) {
    let ultimo_digito = dni[dni.length - 1];
    document.getElementById("ultimo_digito").value = ultimo_digito;
  }
  return false;
}

function Edad() {
  let hoy = new Date();
  let fechaNac = document.getElementById("fecha").value;
  if (fechaNac) {
    fechaNac = new Date(fechaNac);
    let edad = hoy.getFullYear() - fechaNac.getFullYear();
    let mes = hoy.getMonth() - fechaNac.getMonth();
    if (mes < 0 || (mes === 0 && hoy.getDate() < fechaNac.getDate())) {
      edad--;
    }
    document.getElementById("edad").value = edad;
  }
  return false;
}

function procesar() {
  unirNombres();
  ultimoDigito();
  Edad();
  //
  return false;
}
