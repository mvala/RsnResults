#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TRsnFragment.h>
#include <TRsnAction.h>

#include "TRsnSelector.h"

ClassImp(TRsnSelector)

TRsnSelector::TRsnSelector(TTree * /*tree*/):
  TSelector(), fChain(0), fFragment(0), fHist(0), fConfig(0) {

}

TRsnSelector::~TRsnSelector() {
//  delete fFragment;
}

void TRsnSelector::Init(TTree *tree) {
  if (!tree)
    return;
  fChain = tree;
  fFragment = new TRsnFragment();
  fChain->SetBranchAddress("rsnFragment", &fFragment);
}

Bool_t TRsnSelector::Notify() {
  if (fChain->GetCurrentFile()) Printf("Fille : %s", fChain->GetCurrentFile()->GetName());

  fConfig = fChain->GetTree()->GetUserInfo();

  return kTRUE;
}

void TRsnSelector::Begin(TTree * /*tree*/) {
}

void TRsnSelector::SlaveBegin(TTree * /*tree*/) {
  TString option = GetOption();

//  fHist = new TH1D("h", "My Hist", 1000, 0.0, 1000);
//  fOutput->Add(fHist);
}

Bool_t TRsnSelector::Process(Long64_t entry) {

  GetEntry(entry);

//  fFragment->Print();

  TIter next(fConfig);
  TRsnAction *act;
  while ((act = (TRsnAction*) next())) {
    act->Apply(fFragment);
  }



  return kTRUE;
}

void TRsnSelector::SlaveTerminate() {
}

void TRsnSelector::Terminate() {
//  fHist = dynamic_cast<TH1D *>(fOutput->FindObject("h"));
//  if (fHist)
//    fHist->DrawCopy();
}

Int_t TRsnSelector::Version() const {
  return 2;
}

Int_t TRsnSelector::GetEntry(Long64_t entry, Int_t getall) {
  return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0;
}
