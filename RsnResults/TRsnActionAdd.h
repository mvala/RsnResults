//
// Class TRsnActionAdd
//
// TODO
//
// authors:
//          Martin Vala (mvala@saske.sk)
//

#ifndef ROOT_TRsnActionAdd
#define ROOT_TRsnActionAdd

#include <TRsnAction.h>

class TRsnActionAdd: public TRsnAction {

public:
  TRsnActionAdd(const char *name="", const char *title="");
  virtual ~TRsnActionAdd();

  virtual void Apply(TRsnFragment*fr);

private:

  ClassDef(TRsnActionAdd, 1)


};

#endif
