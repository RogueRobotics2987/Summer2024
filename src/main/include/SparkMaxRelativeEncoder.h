/*
 * Copyright (c) 2021-2023 REV Robotics
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of REV Robotics nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <stdint.h>

#include <atomic>

#include <wpi/deprecated.h>

#include "rev/REVLibError.h"
#include "rev/RelativeEncoder.h"

namespace rev {

class CANSparkBase;

/**
 * Get an instance of this class by using CANSparkBase::GetEncoder() or
 * CANSparkBase::GetEncoder(SparkMaxRelativeEncoder::Type, int).
 *
 * @deprecated Use SparkRelativeEncoder instead
 */
class WPI_DEPRECATED("Use SparkRelativeEncoder instead") SparkMaxRelativeEncoder
    : public RelativeEncoder {
    // Friend to allow construction
    friend class CANSparkBase;
    friend class SparkRelativeEncoder;

public:
    /**
     * The type of encoder connected to a SPARK MAX
     *
     * @deprecated Use SparkRelativeEncoder::Type instead
     */
    enum class WPI_DEPRECATED("Use SparkRelativeEncoder::Type instead") Type {
        kNoSensor = 0,
        kHallSensor = 1,
        kQuadrature = 2
    };

    // SparkMaxRelativeEncoder(SparkMaxRelativeEncoder&& rhs) = default;
    // SparkMaxRelativeEncoder& operator=(SparkMaxRelativeEncoder&& rhs) = default;

    // SparkMaxRelativeEncoder(const SparkMaxRelativeEncoder& rhs) = default;

    // ~SparkMaxRelativeEncoder() override = default;

    /**
     * Get the position of the motor. This returns the native units
     * of 'rotations' by default, and can be changed by a scale factor
     * using setPositionConversionFactor().
     *
     * @return Number of rotations of the motor
     *
     */
    double GetPosition() const override;

    /**
     * Get the velocity of the motor. This returns the native units
     * of 'RPM' by default, and can be changed by a scale factor
     * using setVelocityConversionFactor().
     *
     * @return Number the RPM of the motor
     *
     */
    double GetVelocity() const override;

    /**
     * Set the position of the encoder.
     *
     * @param position Number of rotations of the motor
     *
     * @return REVLibError::kOk if successful
     */
    REVLibError SetPosition(double position) override;

    /**
     * Set the conversion factor for position of the encoder. Multiplied by the
     * native output units to give you position
     *
     * @param factor The conversion factor to multiply the native units by
     *
     * @return REVLibError::kOk if successful
     */
    REVLibError SetPositionConversionFactor(double factor) override;

    /**
     * Set the conversion factor for velocity of the encoder. Multiplied by the
     * native output units to give you velocity
     *
     * @param factor The conversion factor to multiply the native units by
     *
     * @return REVLibError::kOk if successful
     */
    REVLibError SetVelocityConversionFactor(double factor) override;

    /**
     * Get the conversion factor for position of the encoder. Multiplied by the
     * native output units to give you position
     *
     * @return The conversion factor for position
     */
    double GetPositionConversionFactor() const override;

    /**
     * Get the conversion factor for velocity of the encoder. Multiplied by the
     * native output units to give you velocity
     *
     * @return The conversion factor for velocity
     */
    double GetVelocityConversionFactor() const override;

    /**
     * Set the sampling depth of the velocity calculation process for a
     * quadrature or hall sensor encoder. This value sets the number of samples
     * in the average for velocity readings. For a quadrature encoder, this can
     * be any value from 1 to 64 (default). For a hall sensor, it must be either
     * 1, 2, 4, or 8 (default).
     *
     * @param depth The velocity calculation process's sampling depth
     *
     * @return REVLibError::kOk if successful
     */
    REVLibError SetAverageDepth(uint32_t depth) override;

    /**
     * Set the position measurement period used to calculate the velocity of a
     * quadrature or hall sensor encoder. For a quadrature encoder, this number
     * may be between 1 and 100 (default). For a hall sensor, this number may be
     * between 8 and 64. The default for a hall sensor is 32ms.
     *
     * The basic formula to calculate velocity is change in position / change in
     * time. This parameter sets the change in time for measurement.
     *
     * @param period_ms Measurement period in milliseconds
     *
     * @return REVLibError::kOk if successful
     */
    REVLibError SetMeasurementPeriod(uint32_t period_ms) override;

    /**
     * Get the velocity calculation process's sampling depth for a quadrature or
     * hall sensor encoder.
     *
     * @return The velocity calculation averaging process's sampling depth
     */
    uint32_t GetAverageDepth() const override;

    /**
     * Get the position measurement period used to calculate the velocity of a
     * quadrature or hall sensor encoder.
     *
     * @return Measurement period in milliseconds
     */
    uint32_t GetMeasurementPeriod() const override;

    /**
     * Get the counts per revolution of the quadrature encoder.
     *
     * For a description on the difference between CPR, PPR, etc. go to
     * https://www.cuidevices.com/blog/what-is-encoder-ppr-cpr-and-lpr
     *
     * @return Counts per revolution
     */
    uint32_t GetCountsPerRevolution() const override;

    /**
     * Set the phase of the MotorFeedbackSensor so that it is set to be in
     * phase with the motor itself. This only works for quadrature
     * encoders. This will throw an error if the user tries to set
     * inverted while the SparkMax is Brushless and using the hall
     * effect sensor.
     *
     * @param inverted The phase of the encoder
     *
     * @return REVLibError::kOk if successful
     */
    REVLibError SetInverted(bool inverted) override;

    /**
     * Get the phase of the MotorFeedbackSensor. This will just return false
     * if the user tries to get inverted while the SparkMax is
     * Brushless and using the hall effect sensor.
     *
     * @return The phase of the encoder
     */
    bool GetInverted() const override;

private:
    CANSparkBase* m_device;
    int m_countsPerRev;
    //Type m_type;

    explicit SparkMaxRelativeEncoder(CANSparkBase& device, Type Type,
                                    int countsPerRev);

    int GetSparkMaxFeedbackDeviceID() const override;
};

}  // namespace rev
