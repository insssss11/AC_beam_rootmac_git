void beam(int runno=1){

  char infile[256];
  char outfile[256];

  sprintf(infile,"bm%02d.txt",runno);
  sprintf(outfile,"bm%02d.root",runno);
  
  std::ifstream inf1(infile);
  int adc1, adc2, adc3, adc4, adc5, tdc1, tdc2, tdc3, tdc4, tdc5;

  TTree * tree = new TTree("tree","title");

  tree->Branch("adc1",&adc1,"adc1/I");
  tree->Branch("adc2",&adc2,"adc2/I");
  tree->Branch("adc3",&adc3,"adc3/I");
  tree->Branch("adc4",&adc4,"adc4/I");
  tree->Branch("adc5",&adc5,"adc5/I");
  tree->Branch("tdc1",&tdc1,"adc1/I");
  tree->Branch("tdc2",&tdc2,"adc2/I");
  tree->Branch("tdc3",&tdc3,"adc3/I");
  tree->Branch("tdc4",&tdc4,"tdc4/I");
  tree->Branch("tdc5",&tdc5,"tdc5/I");


  while(inf1>>adc1>>adc2>>adc3>>adc4>>adc5>>tdc1>>tdc2>>tdc3>>tdc4>>tdc5){
    tree->Fill();
  }
  
  TFile * fout=new TFile(outfile,"recreate");
  tree->Write();
  //  fout->Close();
}
