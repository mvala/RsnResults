{

  TProof::Open("");
  gProof->UploadPackage("pars/RsnUtils.par");
  gProof->EnablePackage("RsnUtils.par");
  gProof->UploadPackage("pars/RsnResults.par");
  gProof->EnablePackage("RsnResults.par");


  TFile *_file0 = TFile::Open("RsnOutput.root");
  sh = new TRsnSparseHandler(Unlike);

  sh->SetAxisFragments(1, TRsnUtils::RangeFragments(Unlike->Projection(1), 0.5));

  sh->SetAxisRangeUser(3, -0.091, 0.1);
  sh->SetAxisElement("IM");
  sh->Print();

  gg = sh->MakeGroupFragments();
  sh->AddFragmentElement(Unlike);
  sh->AddFragmentElement(LikePP);
  sh->AddFragmentElement(MixingMM);
  gg->Print("17");


  TFile *f = TFile::Open("RsnGroup.root","RECREATE");
  TTree *t = new TTree("rsnGroupTree","");

  t->GetUserInfo()->Add(new TRsnActionNorm("normTest","Norm"));
  t->GetUserInfo()->Add(new TRsnActionAdd("addTest","Add"));

//  TRsnFragment *fragment = new TRsnFragment();
//  t->Branch("rsnFragment", "TRsnFragment", &fragment);

  TRsnFragment *fr = 0;


  TObjArray *fragments = gg->GetListOfFragments();
  for (Int_t i=0; i< 1; i++) {
    fr = (TRsnFragment*) fragments->At(i);
    t->Branch("rsnFragment", "TRsnFragment", &fr);

    fr->Print();
    t->Fill();

  }

  t->Write();
  f->Close();

  //  .L macros/Highlight.C+
  //  DrawHighlightFragments(gg, "MixingMM_IM")
}
