#ifndef TRsnSelector_H
#define TRsnSelector_H

#include <TTree.h>
#include <TSelector.h>

class TRsnFragment;
class TH1D;

class TRsnSelector: public TSelector {

public:

  TRsnSelector(TTree *tree = 0);
  virtual ~TRsnSelector();

  virtual Int_t Version() const;
  virtual void Begin(TTree */*tree*/);
  virtual void SlaveBegin(TTree *tree);
  virtual void Init(TTree *tree);
  virtual Bool_t Notify();
  virtual Bool_t Process(Long64_t entry);
  virtual Int_t GetEntry(Long64_t entry, Int_t getall = 0);
  virtual void SlaveTerminate();
  virtual void Terminate();

private:

  TTree *fChain;                    //!pointer to the analyzed TTree or TChain
  TRsnFragment *fFragment;
  TH1D  *fHist;
  TList *fConfig;

  ClassDef(TRsnSelector, 1)


};

#endif
