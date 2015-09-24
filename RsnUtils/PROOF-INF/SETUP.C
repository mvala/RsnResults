Int_t SETUP(TList *input = 0) {

  //if (gSystem->Load("libPhysics.so") < 0)
  //  return 1;

  if (gSystem->Load("libRsnUtils.so") < 0)
    return 1;

  // Set the include paths
  gROOT->ProcessLine(".include RsnUtils");

  // Set our location, so that other packages can find us
  gSystem->Setenv("RsnUtils_INCLUDE", "RsnUtils");

  return 0;
}
