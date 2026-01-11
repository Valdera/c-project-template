#!/bin/bash

# Problem Template Generator for Competitive Programming
# Creates standardized problem structure with CMake integration

set -e

# Colors for pretty output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Get script directory and project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROBLEMS_DIR="${PROJECT_ROOT}/src/problems"

# Print colored message
print_message() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}

# Print header
print_header() {
    echo ""
    print_message "${CYAN}${BOLD}" "╔════════════════════════════════════════════════════╗"
    print_message "${CYAN}${BOLD}" "║     Problem Template Generator                     ║"
    print_message "${CYAN}${BOLD}" "╚════════════════════════════════════════════════════╝"
    echo ""
}

# Get existing platforms
get_existing_platforms() {
    if [ -d "${PROBLEMS_DIR}" ]; then
        find "${PROBLEMS_DIR}" -mindepth 1 -maxdepth 1 -type d -exec basename {} \; | grep -v "^sample$" | sort
    fi
}

# Display platform selection menu
select_platform() {
    local platforms=($(get_existing_platforms))

    print_message "${YELLOW}${BOLD}" "Select problem platform:"
    echo ""

    local i=1
    for platform in "${platforms[@]}"; do
        echo "  ${i}) ${platform}"
        ((i++))
    done
    echo "  ${i}) [Create new platform]"
    echo ""

    while true; do
        read -p "$(echo -e ${BLUE}Enter number [1-${i}]:${NC} )" choice

        if [[ "$choice" =~ ^[0-9]+$ ]] && [ "$choice" -ge 1 ] && [ "$choice" -le "$i" ]; then
            if [ "$choice" -eq "$i" ]; then
                # Create new platform
                while true; do
                    read -p "$(echo -e ${BLUE}Enter new platform name:${NC} )" new_platform
                    if [[ "$new_platform" =~ ^[a-z0-9_-]+$ ]]; then
                        PLATFORM="$new_platform"
                        NEW_PLATFORM=true
                        break
                    else
                        print_message "${RED}" "❌ Invalid platform name. Use only lowercase letters, numbers, hyphens, and underscores."
                    fi
                done
            else
                PLATFORM="${platforms[$((choice-1))]}"
                NEW_PLATFORM=false
            fi
            break
        else
            print_message "${RED}" "❌ Invalid choice. Please try again."
        fi
    done
}

# Get problem name
get_problem_name() {
    echo ""
    print_message "${YELLOW}${BOLD}" "Enter problem name:"
    print_message "${CYAN}" "Examples: 2180_problem_A, problem_1068, starters_187_a"
    echo ""

    while true; do
        read -p "$(echo -e ${BLUE}Problem name:${NC} )" problem_name

        if [ -z "$problem_name" ]; then
            print_message "${RED}" "❌ Problem name cannot be empty."
            continue
        fi

        if ! [[ "$problem_name" =~ ^[a-zA-Z0-9_-]+$ ]]; then
            print_message "${RED}" "❌ Invalid problem name. Use only letters, numbers, hyphens, and underscores."
            continue
        fi

        # Check if problem already exists
        if [ -d "${PROBLEMS_DIR}/${PLATFORM}/${problem_name}" ]; then
            print_message "${RED}" "❌ Problem '${problem_name}' already exists in platform '${PLATFORM}'."
            continue
        fi

        PROBLEM_NAME="$problem_name"
        break
    done
}

# Confirm creation
confirm_creation() {
    echo ""
    print_message "${YELLOW}${BOLD}" "═══ Summary ═══"
    echo ""
    echo "  Platform:     ${PLATFORM}"
    if [ "$NEW_PLATFORM" = true ]; then
        print_message "${CYAN}" "                (new platform will be created)"
    fi
    echo "  Problem:      ${PROBLEM_NAME}"
    echo "  Location:     src/problems/${PLATFORM}/${PROBLEM_NAME}"
    echo ""

    read -p "$(echo -e ${BLUE}Create problem? [Y/n]:${NC} )" confirm

    if [[ ! "$confirm" =~ ^[Yy]?$ ]]; then
        print_message "${YELLOW}" "❌ Cancelled."
        exit 0
    fi
}

# Create platform directory structure
create_platform() {
    local platform_dir="${PROBLEMS_DIR}/${PLATFORM}"

    if [ ! -d "$platform_dir" ]; then
        print_message "${GREEN}" "✓ Creating new platform: ${PLATFORM}"
        mkdir -p "$platform_dir"

        # Create platform-level CMakeLists.txt
        cat > "${platform_dir}/CMakeLists.txt" << EOF
set(SUB_TYPE "${PLATFORM}")

subdirlist(SUBDIRS \${CMAKE_CURRENT_SOURCE_DIR})

foreach (subdir \${SUBDIRS})
    add_subdirectory(\${subdir})
endforeach ()
EOF
    fi
}

# Create problem directory structure
create_problem_structure() {
    local problem_dir="${PROBLEMS_DIR}/${PLATFORM}/${PROBLEM_NAME}"

    print_message "${GREEN}" "✓ Creating problem directory structure..."

    mkdir -p "${problem_dir}/data"
    mkdir -p "${problem_dir}/include"
}

# Create CMakeLists.txt
create_cmake_file() {
    local problem_dir="${PROBLEMS_DIR}/${PLATFORM}/${PROBLEM_NAME}"

    print_message "${GREEN}" "✓ Generating CMakeLists.txt..."

    cat > "${problem_dir}/CMakeLists.txt" << 'EOF'
get_filename_component(TITLE ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_definitions(-DSRC_PATH="${CMAKE_CURRENT_SOURCE_DIR}/data")

set(APP_NAME "${TYPE}-${SUB_TYPE}-${TITLE}")
set(APP_STATIC "${APP_NAME}_static")
set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build")

add_library(${APP_STATIC} STATIC ${APP_SOURCES})

target_include_directories(${APP_STATIC} PUBLIC include)
target_precompile_headers(${APP_STATIC} PUBLIC <string>)

target_link_libraries(${APP_STATIC} PUBLIC
)

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} ${APP_STATIC})
EOF
}

# Create main.cpp template
create_main_file() {
    local problem_dir="${PROBLEMS_DIR}/${PLATFORM}/${PROBLEM_NAME}"

    print_message "${GREEN}" "✓ Generating main.cpp template..."

    cat > "${problem_dir}/main.cpp" << 'EOF'
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Type shortcuts
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

// Common templates
template<typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T mod_pow(T base, T exp, T mod) {
    T result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;
const int MAX_N = 2e5 + 5;

// Debug
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// File I/O setup
void setup_io() {
#ifndef ONLINE_JUDGE
    string input_path = string(SRC_PATH) + "/input.txt";
    string output_path = string(SRC_PATH) + "/output.txt";

    freopen(input_path.c_str(), "r", stdin);
    freopen(output_path.c_str(), "w", stdout);
#endif
}

// ============================================================================
// Solution
// ============================================================================

void solve() {
    // TODO: Implement solution

}

// ============================================================================
// Main
// ============================================================================

int main() {
    fast_io();
    setup_io();

    clock_t start_time = clock();

    int t = 1;
    cin >> t;  // Comment this line if single test case

    while (t--) {
        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end_time = clock();
    cerr << "\nTime: " << fixed << setprecision(6)
         << (double)(end_time - start_time) / CLOCKS_PER_SEC << " sec\n";
#endif

    return 0;
}
EOF
}

# Create empty data files
create_data_files() {
    local problem_dir="${PROBLEMS_DIR}/${PLATFORM}/${PROBLEM_NAME}"

    print_message "${GREEN}" "✓ Creating data files..."

    touch "${problem_dir}/data/input.txt"
    touch "${problem_dir}/data/output.txt"
}

# Print success message
print_success() {
    echo ""
    print_message "${GREEN}${BOLD}" "╔════════════════════════════════════════════════════╗"
    print_message "${GREEN}${BOLD}" "║     ✓ Problem created successfully!                ║"
    print_message "${GREEN}${BOLD}" "╚════════════════════════════════════════════════════╝"
    echo ""

    print_message "${CYAN}" "Location: ${BOLD}src/problems/${PLATFORM}/${PROBLEM_NAME}/${NC}"
    echo ""
    print_message "${YELLOW}" "Next steps:"
    echo "  1. Edit ${BOLD}main.cpp${NC} and implement your solution"
    echo "  2. Add test cases to ${BOLD}data/input.txt${NC} and ${BOLD}data/output.txt${NC}"
    echo "  3. Build and run:"
    echo ""
    print_message "${CYAN}" "     cd build && cmake .. && make"
    print_message "${CYAN}" "     ./problems-${PLATFORM}-${PROBLEM_NAME}"
    echo ""
}

# ============================================================================
# Main execution
# ============================================================================

main() {
    print_header

    # Interactive prompts
    select_platform
    get_problem_name
    confirm_creation

    echo ""
    print_message "${YELLOW}${BOLD}" "Creating problem..."
    echo ""

    # Create structure
    if [ "$NEW_PLATFORM" = true ]; then
        create_platform
    fi

    create_problem_structure
    create_cmake_file
    create_main_file
    create_data_files

    print_success
}

# Run main
main
