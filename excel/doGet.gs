function doGet(e) {
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  var foglioPresenze = ss.getSheetByName("Presenze");
  var foglioAnagrafica = ss.getSheetByName("Anagrafica");
  
  var idLetto = e.parameter.uid; // ID inviato dall'Arduino
  var d = new Date();
  
  // 1. Cerca l'ID nel foglio Anagrafica
  var datiAnagrafica = foglioAnagrafica.getDataRange().getValues();
  var nomeTrovato = "Sconosciuto";
  var cognomeTrovato = "Sconosciuto";
  
  for (var i = 1; i < datiAnagrafica.length; i++) {
    if (datiAnagrafica[i][0] == idLetto) { // Se l'ID corrisponde (Colonna A)
      nomeTrovato = datiAnagrafica[i][1];    // Prendi Nome (Colonna B)
      cognomeTrovato = datiAnagrafica[i][2]; // Prendi Cognome (Colonna C)
      break;
    }
  }
  
  // 2. Registra i dati nel foglio Presenze
  foglioPresenze.appendRow([d, idLetto, nomeTrovato, cognomeTrovato]);
  
  // 3. Risposta per l'Arduino
  return ContentService.createTextOutput("Registrato: " + nomeTrovato + " " + cognomeTrovato).setMimeType(ContentService.MimeType.TEXT);
}
