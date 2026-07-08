package wrzepka.backend;

import java.io.Serializable;
import java.time.OffsetDateTime;
import java.util.Objects;

public class WeatherTelemetryId implements Serializable {

    private OffsetDateTime dateTime;
    private String deviceId;

    public WeatherTelemetryId() {

    }

    public WeatherTelemetryId(OffsetDateTime dateTime, String deviceId) {
        this.dateTime = dateTime;
        this.deviceId = deviceId;
    }

    public OffsetDateTime getDateTime() {
        return dateTime;
    }

    public String getDeviceId() {
        return deviceId;
    }

    public void setDateTime(OffsetDateTime dateTime) {
        this.dateTime = dateTime;
    }

    public void setDeviceId(String deviceId) {
        this.deviceId = deviceId;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WeatherTelemetryId that = (WeatherTelemetryId) o;
        return Objects.equals(dateTime, that.dateTime) && Objects.equals(deviceId, that.deviceId);
    }

    @Override
    public int hashCode() {
        return Objects.hash(dateTime, deviceId);
    }
}
