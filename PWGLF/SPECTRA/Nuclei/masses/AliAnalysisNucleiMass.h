#ifndef ALIANALYSISNUCLEIMASS_H
#define ALIANALYSISNUCLEIMASS_H

// ROOT includes
#include <TList.h>

// AliRoot includes
#include <AliAnalysisTaskSE.h>
#include <AliPIDResponse.h>

class AliAODEvent;
class AliESDEvent;
class AliVEvent;
class TH2F;
class TH2D;
class TH1F;
class TF1;
class TH2D;
class TGraph;
class AliESDtrackCuts;
class TProfile;

class AliAnalysisNucleiMass : public AliAnalysisTaskSE {
 public:
  AliAnalysisNucleiMass();
  AliAnalysisNucleiMass(const char *name);
  
  virtual ~AliAnalysisNucleiMass();
  
  virtual void   UserCreateOutputObjects();
  virtual void   UserExec(Option_t *option);
  virtual void   Terminate(Option_t *);

  void SetCentrality(Float_t *fCt) {fCentrality[0]=fCt[0];fCentrality[1]=fCt[1];};
  void SetFilterBit(Int_t TestFilterBit) {FilterBit=TestFilterBit;}
  void SetNTPCcluster(Int_t nTPCcluster) {NminTPCcluster=nTPCcluster;}
  void SetDCAzCut(Float_t fDCAzCut) {DCAzCUT=fDCAzCut;}
  void SetDCAxyCut(Float_t fDCAxyCut) {DCAxyCUT=fDCAxyCut;}
  void SetkTPCcut(Bool_t isTPCcut) {kTPCcut=isTPCcut;}
  
 private:
  AliAnalysisNucleiMass(const AliAnalysisNucleiMass &old); 
  AliAnalysisNucleiMass& operator=(const AliAnalysisNucleiMass &source);

  static const Int_t nbin = 46;     // number of pt bins

  Bool_t fMC;                       // if MC

  Float_t fCentrality[2];           // centrality bin (min and max)
  
  Int_t FilterBit;                  // filter be to be used

  Int_t NminTPCcluster;             // min TPC cluster number

  Float_t DCAzCUT;                  // cut on DCA-z
  Float_t DCAxyCUT;                 // cut on DCA-xy

  Bool_t kTPCcut;                   // to apply a TPC 2 sigma cut

  Bool_t kTPC;                      //! is > NminTPCcluster 
  Bool_t kTOF;                      //! kTOFout and kTIME required

  AliAODEvent* fAOD;                //! AOD object
  
  AliESDEvent* fESD;                //! ESD object
  
  AliVEvent* fEvent;                //! general object
 
  AliPIDResponse *fPIDResponse;     //! pointer to PID response

  TList *fList1;                    //! list for slot 1

  TH1F *hNevent;                    //! Event counter

  TH1F *hZvertex;                   //! z-vertex distribution

  TH2F *fdEdxVSp[3];                //! dedx vs p plots

  TH2F *fBetaTofVSp;                //! beta vs p plots

  TH1F *hTOFSignalPion;             //! pion  TOF signal

  TH2F *fM2vsP_NoTpcCut[3];         //! M2 vs. P
  
  TH2F *fNsigmaTPC[9];              //! NsigmaTPC vs. pT
  
  TH2F *fNsigmaTOF[9];              //! NsigmaTOF vs. pT

  TH2F *fNsigmaTPCvsP_kTOFtrue[18]; //! NsigmaTPC vs. p with kTOFout && kTIME for provide TPC different cuts effect
 
  TProfile *hDeDxExp[9];            //! TPC spline used

  TProfile *hBetaExp[9];            //! TOF expected beta
  
  TH2F *fM2vsZ[10];                 //! M2 vs. Z in different pT range

  TH2F *fM2vsP[18];                 //! M2 vs. P with 2 sigma TPC cut for each particle species

  TH1D *hDCAxy[18][nbin];           //! DCA distribution in 2 sigma TPC cut for each particle species

  TH1D *hM2CutDCAxy[18][nbin];      //! M^{2} IN DCA cut (in 2 sigma TPC cut)

  TH1D *hM2CutGroundDCAxy[18][nbin];//! M^{2} OUT DCA cut (in 2 sigma TPC cut)

  TH2F *fM2vsP_NoTpcCut_DCAxyCut[3];//! M^{2} vs. P with a DCAxy cut  

  TH2F *fM2vsP_DCAxyCut[18];        //! M^{2} vs. P with a DCAxy cut (2sigma TPC cut)
  
   
  ClassDef(AliAnalysisNucleiMass, 1);
};

#endif
