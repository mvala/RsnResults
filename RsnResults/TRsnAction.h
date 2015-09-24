//
// Class TRsnAction
//
// TODO
//
// authors:
//          Martin Vala (mvala@saske.sk)
//

#ifndef ROOT_TRsnAction
#define ROOT_TRsnAction

#include <TNamed.h>
#include "TRsnFragment.h"
class TRsnAction: public TNamed {

public:
  TRsnAction(const char *name, const char *title);
  virtual ~TRsnAction();

  virtual  void Apply(TRsnFragment*fr) = 0;

private:

  ClassDef(TRsnAction, 1)


};

#endif
