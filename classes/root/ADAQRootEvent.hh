/////////////////////////////////////////////////////////////////////////////////
//
// name: ADAQRootEvent.hh
// date: 19 Dec 14
// auth: Zach Hartwig
// mail: hartwig@psfc.mit.edu
// 
// desc: The ADAQRootEvent C++class provides a generic container for
//       the essential event-level data of a particle detector that is
//       modelled with Monte Carlo particle transport methods. This
//       class is designed to provide a straightforward and universal
//       method of persistently storing event-level data for later
//       analysis within the ADAQ framework. This class is designed to
//       be used within the ROOT framework and utilizes ROOT data
//       types to ensure compatibility with post-simulation analysis
//       tools built using ROOT and for portability between
//       platforms. For a standalone C++ event class, see
//       $ADAQ/classes/c++/ADAQEvent.hh.
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __ADAQRootEvent_hh__ 
#define __ADAQRootEvent_hh__ 1

#include <TObject.h>
#include <TString.h>

#include <vector>

class ADAQEvent : public TObject
{
public:

  ADAQEvent() {Initialize();}
  ~ADAQEvent();

  // Method to initialize/reset all member data
  void Initialize(){
    EventID = RunID = 0;
    TotalEDep = 0.;
    PhotonsCreated = PhotonDetected = 0;
    PhotonCreationTime.clear();
    PhotonDetectionTime.clear();
    VertexPos[0] = VertexPos[1] = VertexPos[2] = 0.;
    VertexMomDir[0] = VertexMomDir[1] = VertexMomDir[2] = 0.;
    VertexKE = 0.;
    VertexPCode = 0;
  }

  // The ID of the detector event
  void SetEventID(Int_t EID) {EventID = EID;}
  Int_t GetEventID() {return EventID;}

  // The ID of the simulation run
  void SetRunID(Int_t RID) {RunID = RID;}
  Int_t GetRunID() {return RunID;}

  // The total ionizing energy deposited
  void SetTotalEDep(Double_t TED) {TotalEDep = TED;}
  Double_t GetTotalEDep() {return TotalEDep;}

  // The number of scintillation/Cerenkov photons created
  void SetPhotonsCreated(Int_t PC) {PhotonsCreated = PC;}
  Int_t GetPhotonsCreated() {return PhotonsCreated;}

  // The number of scintillation/Cerenkov photons detected
  void SetPhotonsDetected(Int_t PD) {PhotonsDetected = PD;}
  Int_t GetPhotonsDetected() {return PhotonsDetected;}

  // Control of vector of scintillation/Cerenkov photon creation time
  void AddPhotonCreationTime(Double_t PCT) {PhotonCreationTime.push_back(PCT);}
  void ClearPhotonCreationTime() {PhotonCreationTime.clear();}
  vector<Double_t> GetPhotonCreationTime() {return PhotonCreationTime;}

  // Control of vector of scintillation/Cerenkov photon detection time
  void AddPhotonDetectionTime(Double_t PDT) {PhotonDetectionTime.push_back(PDT);}
  void ClearPhotonDetectionTime() {PhotonDetectionTime.clear();}
  vector<Double_t> GetPhotonDetectionTime() {return PhotonDetectionTime;}

  // The position of the vertex (track ID == 0) particle
  void SetVertexPos(Double_t VX, Double_t VY, Double_t VZ)
  {VertexPos[0] = VX; VertexPos[1] = VY; VertexPos[2] = VZ;}

  // The momentum direction of the vertex particle
  void SetVertexMomDir(Double_t PX, Double_t PY, Double_t PZ)
  {VertexMomDir[0] = PX; VertexMomDir[1] = PY; VertexPosDir[2] = PZ;}

  // The kinetic energy of the vertex particle particle
  void SetVertexKE(Double_t VKE) {VertexKE = VKE;}
  Double_t GetVertexKE() {return VertexKE;}

  // A unique integer particle ID of the vertex particle
  void SetVertexPCode(Int_t VPC) {VertexPCode = VPC;}
  Int_t GetVertexPCode() {return VertexPCode;}
  

private:

  // Event metadata
  Int_t EventID, RunID;

  // Generic detector data
  Double_t TotalEDep;

  // Scintillation/Cerenkov photon data
  Int_t photonsCreated;
  Int_t photonsDetected;
  vector<Double_t> photonCreationTime;
  vector<double_t> photonDetectionTime;

  // Vertex particle (event track ID == 0) data
  Double_t VertexPos[3];
  Double_t VertexMomDir[3];
  Double_t VertexKE;
  Int_t VertexPCode;

  ClassDef(ADAQEvent, 1);
};
