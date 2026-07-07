CREATE EXTENSION IF NOT EXISTS timescaledb;

create table weather_telemetry (
	date_time timestamptz,
	device_id varchar(10) not null,
	pressure REAL not null,
	temperature REAL not null,
	humidity REAL not null,
	light_intensity INTEGER not null,
	constraint pk_weather_telemetry PRIMARY KEY (device_id, date_time)
);

SELECT create_hypertable('weather_telemetry', 'date_time');