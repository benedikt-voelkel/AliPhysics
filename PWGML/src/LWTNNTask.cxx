// Implementation of LWTNNTask

#include "AliMCEvent.h"

#include "LWTNNTask.h"


LWTNNTask::LWTNNTask(const std::vector<std::string>& featureNames,
                     const std::string& modelFile,
                     const std::unordered_map<std::string, std::string>&\
                     lwtnnBranchNamesMap)
  : AliAnalysisTaskSE(), mFeatureNames(featureNames),
    mMLManager(&(MLManager::getInstance()))
{
  mMLManager->setFeatures(featureNames);

  mLWTNNKernelID = mMLManager->createKernel(EMLBackend::kLWTNN, modelFile,
                                            lwtnnBranchNamesMap);
}

LWTNNTask::UserExec(Option_t *option)
{
  // Get values from event
  /*
  FillFeatureMap(GetMCEvent());
  */
  mMLManager->setInputs(mFeatureValueMap);
  mMLManager->compute();
  mMLManager->getPredictions(mPredictions);
  /*
  DoStuff(mPredictions);
  */
}

LWTNNTask::Terminate()
{
}
