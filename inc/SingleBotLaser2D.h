#ifndef _GRIDSLAM_SINGLEBOTLASER2D_H_
#define _GRIDSLAM_SINGLEBOTLASER2D_H_

#include "Config.h"
#include "Type.h"
#include "MotionModel.h"
#include <vector>
#include <string>
#include <Eigen/Eigen>

namespace gslam
{
    class SingleBotLaser2DGrid {
    public:
        SingleBotLaser2DGrid(const Pose2D &bot_pose, const BotParam &param,
            const Storage2D<uint8_t> &map);

        real rayCast(const Pose2D &pose) const;

        SensorData scan() const;
        bool botAction(real t, real r);
        
        // Get Function
        Eigen::MatrixXf getMap(){
            return m_imageMap;
        }

        Pose2D getPose(){
            return m_pose;
        }

        BotParam getParam(){
            return m_param;
        }

        std::vector<Pose2D> getTraj(){
            return m_traj;
        }

        void setPose(const Pose2D &pose) {
            m_pose = pose;
            m_traj.clear();
            m_traj.push_back(pose);
        }
    private:
        MatrixXf m_imageMap;
        Pose2D m_pose;
        BotParam m_param;
        std::vector <Pose2D> m_traj;
    };
}

#endif