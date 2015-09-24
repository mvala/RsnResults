Int_t SETUP(TList *input = 0) {

  //if (gSystem->Load("libPhysics.so") < 0)
  //  return 1;

  if (gSystem->Load("libRsnResults.so") < 0)
    return 1;

  // Set the include paths
  gROOT->ProcessLine(".include RsnResults");

  // Set our location, so that other packages can find us
  gSystem->Setenv("RsnResults_INCLUDE", "RsnResults");

  return 0;
}
