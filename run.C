{

  TProof::Open("");
  gProof->UploadPackage("pars/RsnUtils.par");
  gProof->EnablePackage("RsnUtils.par");
  gProof->UploadPackage("pars/RsnResults.par");
  gProof->EnablePackage("RsnResults.par");

  TChain ch("rsnGroupTree");
  ch.AddFile("RsnGroup.root");
  ch.Process("TRsnSelector.cxx+g");
  }

