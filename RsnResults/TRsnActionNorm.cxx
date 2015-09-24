//
// Class TRsnActionNorm
//
// TODO
//
// authors:
//          Martin Vala (mvala@saske.sk)
//

#include "TRsnActionNorm.h"

ClassImp(TRsnActionNorm)

//_________________________________________________________________________________________________
TRsnActionNorm::TRsnActionNorm(const char *name, const char *title):
  TRsnAction(name, title) {
//
// Standard constructor
//

}

//_________________________________________________________________________________________________
TRsnActionNorm::~TRsnActionNorm() {
//
// Destructor
//
}

void TRsnActionNorm::Apply(TRsnFragment*fr) {
  printf("[name=%s]Norming Fragment : ",GetName());
  fr->Print();

}
