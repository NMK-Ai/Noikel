#!/usr/bin/bash
export API_HOST=https://api.konik.ai
export ATHENA_HOST=wss://athena.konik.ai
export MAPS_HOST=https://api.konik.ai/maps
export SKIP_FW_QUERY=1

exec ./launch_chffrplus.sh
