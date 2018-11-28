// Test task running LWTNN via AliNN wrapper in a task

#ifndef LWTNN_TASK_H_
#define LWTNN_TASK_H_

#include <string>

#include "MLInferer/MLManager.h"
#include "MLInferer/Types.h"

#include "AliAnalysisTaskSE.h"

class AliMCEvent;

class LWTNNTask : public AliAnalysisTaskSE
{
  public:
    /// Only allow standard constructor
    LWTNNTask(const std::string& modelFile);

    virtual ~LWTNNTask();

    virtual void UserExec(Option_t *option) override;
    virtual void UserCreateOutputObjects() override;
    virtual void Terminate(Option_t *option) override;

    void PrepareFeatureMap(AliMCEvent* event);

  private:
    LWTNNTask();
    LWTNNTask(const LWTNNTask&);
    LWTNNTask& operator=(const LWTNNTask&);

  private:
    /// The pointer to the global MLManager
    mlinference::base::MLManager* mMLManager;
    /// Branches to be processed
    std::vector<std::string> mFeatureNames;
    /// Mapping values of an event to the feature names
    std::unordered_map<std::string, double> mFeatureValueMap;
    /// Map of predictions for each registered MLKernel (by id)
    std::vector<std::unordered_map<std::string,double>> mPredictions;
};


#endif
