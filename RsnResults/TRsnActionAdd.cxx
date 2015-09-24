//
// Class TRsnActionAdd
//
// TODO
//
// authors:
//          Martin Vala (mvala@saske.sk)
//

#include "TRsnActionAdd.h"

ClassImp(TRsnActionAdd)

//_________________________________________________________________________________________________
TRsnActionAdd::TRsnActionAdd(const char *name, const char *title):
  TRsnAction(name, title) {
//
// Standard constructor
//

}

//_________________________________________________________________________________________________
TRsnActionAdd::~TRsnActionAdd() {
//
// Destructor
//
}

void TRsnActionAdd::Apply(TRsnFragment*fr) {

  printf("[name=%s]Adding Fragment : ",GetName());
  fr->Print();
}
