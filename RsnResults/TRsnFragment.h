// Authors: Jan Musinsky (jan.musinsky@cern.ch)
//          Martin Vala  (martin.vala@cern.ch)
// Date:    2015-04-17

#ifndef RSNFRAGMENT_H
#define RSNFRAGMENT_H

#include <TObjArray.h>

class TRsnGroup;

class TRsnFragment: public TObject {

public:
  TRsnFragment();
  TRsnFragment(Double_t min, Double_t max, TRsnGroup *group);
  virtual ~TRsnFragment();

  Double_t      GetMin() const { return fMin; }
  Double_t      GetMax() const { return fMax; }
  Double_t      GetMean() const { return (fMin+fMax)/2.0; }
  Double_t      GetWidth() const { return TMath::Abs(fMax-fMin); }
  TRsnGroup    *GetGroup() const { return fGroup; }
  TObjArray    *GetListOfElements() const { return fElements; }
  Int_t         GetNElements() const { return fElements ? fElements->GetEntries() : -1; } // no fast
  static TList *GetListOfAllElements();

  virtual Int_t  Compare(const TObject *obj) const;
  virtual Bool_t IsSortable() const { return kTRUE; }
  virtual void   Print(Option_t *option = "") const;

  Int_t         AddElement(TObject *obj, const char *tag);
  TObject      *FindElement(const char *tag) const;
  const char   *FindElement(const TObject *obj) const;

private:
  Double_t      fMin;          // min
  Double_t      fMax;          // max
  TRsnGroup    *fGroup;        // pointer to parent group
  TObjArray    *fElements;     // list of unique elements

  static TList *fgAllElements; // list of all elements of all fragments

  ClassDef(TRsnFragment, 1) // RsnFragment class
};

#endif
