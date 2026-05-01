#include "TACSBoldMaterial.h"
#include <cmath>

// Statische Definition des Namens
const char *TACSBoldMaterial::constName = "TACSBoldMaterial";

// --- Konstruktor und Destruktor ---

TACSBoldMaterial::TACSBoldMaterial(TACSMaterialProperties *_props) {
  props = _props;
  if (props) {
    props->incref();
  }
}

TACSBoldMaterial::~TACSBoldMaterial() {
  if (props) {
    props->decref();
  }
}

// --- Getter-Methoden ---

int TACSBoldMaterial::getNumStresses() {
  return 6; // 3D-Fall
}

const char *TACSBoldMaterial::getObjectName() {
  return constName;
}

// --- Physikalische Implementierungen (aktuell Platzhalter) ---

TacsScalar TACSBoldMaterial::evalDensity(int elemIndex, const double pt[], const TacsScalar X[]) {
  if (props) {
    return props->getDensity();
  }
  return 0.0;
}

TacsScalar TACSBoldMaterial::evalSpecificHeat(int elemIndex, const double pt[], const TacsScalar X[]) {
  // Für rein mechanische Simulationen nicht erforderlich.
  return 0.0;
}

void TACSBoldMaterial::evalStress(int elemIndex, const double pt[], const TacsScalar X[],
                                  const TacsScalar strain[], TacsScalar stress[]) {
  // TODO: HIER KOMMT DIE IMPLEMENTIERUNG DER BOLD-GLEICHUNGEN
  // strain[] enthält die Komponenten des Green-Lagrange-Dehnungstensors E
  // in Voigt-Notation: [E_xx, E_yy, E_zz, 2*E_yz, 2*E_xz, 2*E_xy]
  // stress[] soll mit den Komponenten des 2. Piola-Kirchhoff-Spannungstensors S
  // in Voigt-Notation gefüllt werden.

  // Als Platzhalter setzen wir die Spannungen vorerst auf Null.
  for (int i = 0; i < 6; i++) {
    stress[i] = 0.0;
  }
}

void TACSBoldMaterial::evalTangentStiffness(int elemIndex, const double pt[],
                                            const TacsScalar X[], TacsScalar C[]) {
  // TODO: HIER KOMMT DIE IMPLEMENTIERUNG DER KONSISTENTEN TANGENTENSTEIFIGKEIT
  // C[] ist eine 6x6-Matrix (als flaches Array mit 36 Elementen), die die
  // Ableitung dS/dE darstellt.

  // Als Platzhalter setzen wir die Steifigkeit vorerst auf Null.
  for (int i = 0; i < 36; i++) {
    C[i] = 0.0;
  }
}
