#ifndef TACS_BOLD_MATERIAL_H
#define TACS_BOLD_MATERIAL_H

#include "TACSConstitutive.h"
#include "TACSMaterialProperties.h"

/**
  Konstitutives Modell für ein hyperelastisches Material nach dem BOLD-Modell.

  Diese Klasse implementiert das BOLD-Materialmodell für 3D-Volumenkörper.
  Sie erwartet, dass die Materialparameter (z.B. mu, J_m) über ein
  TACSMaterialProperties-Objekt bereitgestellt werden.
*/
class TACSBoldMaterial : public TACSConstitutive {
 public:
  /**
    Der Konstruktor für das BOLD-Materialmodell.

    @param _props Die Materialeigenschaften, die die Parameter für das BOLD-Modell enthalten.
  */
  TACSBoldMaterial(TACSMaterialProperties *_props);
  ~TACSBoldMaterial();

  // --- Geforderte Implementierungen von TACSConstitutive ---

  /**
    Gibt die Anzahl der Spannungs-/Dehnungskomponenten zurück.
    Für 3D ist dies 6 (sigma_xx, sigma_yy, sigma_zz, sigma_yz, sigma_xz, sigma_xy).
  */
  int getNumStresses();

  /**
    Berechnet die Dichte des Materials.
  */
  TacsScalar evalDensity(int elemIndex, const double pt[], const TacsScalar X[]);

  /**
    Berechnet die spezifische Wärme (hier nicht relevant, Dummy-Implementierung).
  */
  TacsScalar evalSpecificHeat(int elemIndex, const double pt[], const TacsScalar X[]);

  /**
    Die Kernfunktion: Berechnet die Spannungen aus den Dehnungen.
    Hier wird die konstitutive Gleichung des BOLD-Modells implementiert.
  */
  void evalStress(int elemIndex, const double pt[], const TacsScalar X[],
                  const TacsScalar strain[], TacsScalar stress[]);

  /**
    Die Kernfunktion für die Nichtlinearität: Berechnet die Tangentensteifigkeit.
    Dies ist die Ableitung der Spannungen nach den Dehnungen.
  */
  void evalTangentStiffness(int elemIndex, const double pt[],
                            const TacsScalar X[], TacsScalar C[]);

  // --- Optional, aber gute Praxis ---

  /**
   Gibt den Namen des Objekts zurück.
  */
  const char *getObjectName();

 private:
  // Pointer auf das Objekt, das unsere Materialparameter hält
  TACSMaterialProperties *props;

  // Name des Modells
  static const char *constName;
};

#endif // TACS_BOLD_MATERIAL_H
