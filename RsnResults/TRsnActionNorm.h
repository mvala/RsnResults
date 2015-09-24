//
// Class TRsnActionNorm
//
// TODO
//
// authors:
//          Martin Vala (mvala@saske.sk)
//

#ifndef ROOT_TRsnActionNorm
#define ROOT_TRsnActionNorm

#include <TRsnAction.h>

class TRsnActionNorm: public TRsnAction {

public:
  TRsnActionNorm(const char *name="", const char *title="");
  virtual ~TRsnActionNorm();

  virtual void Apply(TRsnFragment*fr);

private:

  ClassDef(TRsnActionNorm, 1)


};

#endif
